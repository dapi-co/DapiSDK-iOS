# DapiConnect iOS SDK
![CocoaPods Compatible](https://img.shields.io/cocoapods/v/DapiSDK)

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

You can check out our [iOS Integration Guide](https://dapi-api.readme.io/docs/how-to-integrate-with-ios-sdk) for detailed information about our SDK.

## To Run The Example App

1. Open `AppDelegate` and replace `APP_KEY` with your appKey. Can be obtained from [Dapi Dashboard](https://dashboard.cf.dapi.co/).
2. Replace `App Bundle ID` form  value `com.dapi.app` with your Bundle ID that you added into [Dapi Dashboard](https://dashboard.cf.dapi.co/).
3. run the app.
4. Click `Connect` button to select your bank and enter credentials to login through Dapi.
5. After a successful connection, a DapiConnection object is generated and used for making calls to Dapi endpoints that you can call by clicking on any of the buttons like `Get Identity` and `Create Transfer`.
6. Check our [Docs](https://dapi-api.readme.io/docs/how-to-integrate-with-ios-sdk) for detailed information about our SDK.
