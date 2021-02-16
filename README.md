# DapiConnect iOS SDK
![CocoaPods Compatible](https://img.shields.io/cocoapods/v/DapiConnect)

## Overview

### Introduction

DapiConnect for iOS is a prebuilt SDK that reduces the time it takes to integrate with Dapi's API and gain access to your users financial data.

The SDK provides direct access to Dapi endpoints and offers optional UI to manage users' accounts, subaccounts, balance and money transfer.

### Requirements

- iOS v10.3 or later
- App key (obtain from [Dapi Dashboard](https://dashboard.dapi.co/))
- Latest version of DapiConnect framework (obtain from [DapiConnect.framework](https://github.com/dapi-co/DapiConnect-iOS/releases))
- SDK-Server (see below)
iOS v10.3 or later

## Before you start

Currently, the SDK is only available through [CocoaPods](https://cocoapods.org/#install). 
To start integrating with  [DapiConnect.framework](https://github.com/dapi-co/DapiConnect-iOS/releases):

1. Update your Podfile to include 

```ruby
pod 'DapiSDK'
```
2. Run the following command in your project directory

```console
pod install
```

## Initiate SDK

1. Import DapiConnect in your AppDelegate.

    ```swift
    import DapiConnect
    ```

2. Create Dapi client with your configurations in the AppDelegate in the `didFinishLaunchingWithOptions` method.

    ```swift
    Dapi.start(
    	appKey: "ABC", clientUserID: "MohammedEnnabah") { (dapi, error) in
    }
    ```

    You can get the `appKey` from the dashboard.

    The `clientUserID` is for your own reference. The best practice is to use the userID you would refer to in your system.

3. Let's now create a connection object. As previously mentioned, a connection represents a user's connection to a bank. So if they authenticate and login, through Dapi, to 2 banks there will be 2 connections. 
Since you don't know yet which bank the user will chose, you will just display the connect page. The user has to then pick the bank and enter their credentials. 

    ```swift
    Dapi.shared.presentConnect(self)
    ```

    Add an extension to handle a successful or a failed connection attempt.

    ```swift
    extension ViewController: DapiConnectDelegate {

        func connectDidSuccessfullyConnect(toBankID bankID: String, connection: DapiBankConnection) {
            print(bankID)
        }
        
        func connectDidFailConnecting(toBankID bankID: String, withError error: String) {
            print(error)
        }

    }
    ```

That's it. You can now try to run your app on the simulator and call the `presentConnect` function and see Dapi in action!

Now lets add some functionality to your integration.

## Dapi's Functions

There are 4 main functions that you will use to interact with the SDK.

### **Create Transfer**

Let's create a transfer from an account to another account. 

This could be from the user's account to your own account as a payment.
Or from the user's account to another external account. You can do both.

So in a nutshell, you can send money `from` an account `to` an account with a specific `amount`.

**All 3 variables are optional.**
The behaviour of the SDK will differ if you decide to set or omit these varialbles.

`**to**`
If you are accepting a transfer into your own company's account, you don't need to set a `to`. You can simply add one in your [dashboard](http://dashboard.cf.dapi.co) under your app. The `to` will automatically be set to that account.

If you didn't set a beneficiary on the dashboard AND you didn't add a `to` object in the `createTransfer` function, an error will be thrown.

`**from**`
If you don't set a `from` account, we will simply display a popup screen for your user to pick the account from our UI. 
If you do provide a `from` object, this screen won't be displayed. 
You can create your own accounts list page from the `getAccounts` function.

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cdd733b4-6159-481f-9460-e4fa2677f09a/dapiAccounts.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cdd733b4-6159-481f-9460-e4fa2677f09a/dapiAccounts.png)

`**amount**`
If you don't set an `amount` we will display a screen with a numpad screen for your user to enter the amount in. 

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/51a29e91-c9a0-4256-b7b3-1077c2afac3c/dapiAmount.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/51a29e91-c9a0-4256-b7b3-1077c2afac3c/dapiAmount.png)

```swift
connection.createTransfer 
{ (account, amount, error, operationID) in
    
    if let error = error {
        
        //Failed to transfer
				print(error)
        
    } else {
        
        print(account)
        
    }
    
    
}
```

Now let's say you want a little more control, and would like to set the `amount` and the `from`  account yourself.

Here we will pick the first account in the connection object. Remember, a bank connection might have several accounts, so the accounts object is a list. You will need to pick which account you're sending from.

```swift
connection.createTransfer(from: connection.accounts.first!, amount: 10) 
{ (account, amount, error, operationID) in
    
    if let error = error {
        
        //Failed to transfer
				print(error)
        
    } else {
        
        print(account)
        
    }
    
}
```

Now let's try sending money `to` an external account.

We first need to create a new Object called `Beneficiary`. We will then need to set a few details about the bank account we're sending the money to.

```swift
let beneficiaryInfo = DapiBeneficiaryInfo()
let lineAddress = DapiLinesAddress()
lineAddress.line1 = "baniyas road"
lineAddress.line2 = "dubai"
lineAddress.line3 = "united arab emirates"
beneficiaryInfo.linesAddress =  lineAddress
beneficiaryInfo.accountNumber = "0959040184901"
beneficiaryInfo.bankName = "Emirates NBD Bank PJSC"
beneficiaryInfo.swiftCode = "EBILAEAD"
beneficiaryInfo.iban = "AE140260000959040184901"
beneficiaryInfo.country = "UNITED ARAB EMIRATES"
beneficiaryInfo.branchAddress = "Baniyas Road Deira PO Box 777 Dubai UAE"
beneficiaryInfo.branchName = "Emirates NBD Bank PJSC"
beneficiaryInfo.phoneNumber = "0585859206"
beneficiaryInfo.name = "John Doe"

connection.createTransfer(from: connection.accounts.first!, to: beneficiaryInfo, amount: 10) 
{ (account, amount, error, operationID) in
    
    if let error = error {
        
        //Failed to transfer
				print(error)
        
    } else {
        
        print(account)
        
    }
    
}
```

### Get Accounts

Each bank `connection` will have a list of `accounts`.

```swift
connection.getAccounts { (accounts, error, operationID) in

		if let error = error {
        
				print(error)
        
    } else {
        
        print(accounts)
        
    }

}
```

### Get Identity

Get the identity information that has been confirmed by the bank.

These are the identity details that you will get. Not all banks provide all this data. So we will provide as much of it as possible.

`nationality
dateOfBirth
identification (passport or national ID)
numbers
emailAddress
name
address`

```swift
connection.getIdentity { (identity, error, operationID) in
		
		if let error = error {
        
				print(error)
        
    } else {
        
        print(identity)
        
    }

}
```

### Get Transactions

We can get the list of transactions for each account.

You first have to pick an account for which you would like to access the data. You then need to provide a `from` and `to` fields for the dates. These are optional and if they aren't provided we will just fetch the transactions as far back as the bank will allow us to.

```swift
connection.getTransactionsFor(connection.accounts[0], from: Date(timeIntervalSince1970: 0), to: Date()) 
{ (transactions, error, operationID) in

		if let error = error {
        
				print(error)
        
    } else {
        
        print(transactions)
        
    }

}
```