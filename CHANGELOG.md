# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html).
## 2.40.0 - 2022-2-2
### Added
- Add `showTransferResult` in Dapi Configurations.
- Handle Unknown errors.

## 2.39.0 - 2022-1-31
### Added
- Distributing Multi-arch SDKs for Apple silicon (M1) and Intel-based Platforms.

## 2.36.0 - 2022-1-26
### Added
-  Handel max and min amount for transfers. 

## 2.35.0 - 2022-1-22
### Fixed
-  Remove Xcode warnings


## 2.34.0 - 2022-1-21
### Added
-  Add `autoflowDelegate` delegate called for to track  AutoFlow operations.

## 2.33.0 - 2022-1-12
### Fixed
-  `connectDidDismiss` delegate func called after close button tapped from the connect layer.

## 2.32.0 - 2021-12-21
### Changed
- In `BankWireBeneficiary` the `RoutingNumbers` array to be one `routingNumber` string

## 2.31.0 - 2021-12-03
### Added
- Reference number in create wire transfers with completion named  `completionWithReferenceNumber`.
- Reference number in create transfers with completion named `completionWithReferenceNumber`.


## 2.30.0 - 2021-12-03
### Added
- Support wire transfers for U.S. Banks.
- Support wire beneficiaries for U.S. Banks.

## 2.29.0 - 2021-11-23
### Fixed
- Beneficiary cooldown period

## 2.28.0 - 2021-11-03
### Added
- Swift code to `DapiBankConnection`.

## 2.27.0 - 2021-10-22
### Added
- Post successful connection text.

## 2.26.0 - 2021-10-12
### Changed
- Responses status code check.
- Valid JSON format responses check.

## 2.25.0 - 2021-09-30
### Changed
- URL requests timeout value set to 120s.

## 2.24.0 - 2021-09-26
### Fixed
- 1st party image caching.

## 2.23.0 - 2021-09-23
### Fixed
- Crash caused by animated images.

## 2.21.0 - 2021-08-05
### Fixed
- Crash caused by non error check of timeout.

## 2.20.0 - 2021-08-05
### Added
- present connect with bank ID.
- nickname for beneficiary object.

## 2.19.0 - 2021-07-15
### Fixed
- Remote beneficiary reading.  

## 2.18.0 - 2021-07-14
### Fixed
- Remove path component from server URL.  

## 2.17.0 - 2021-07-13
### Added
- `DAPI_NETWORK_LOGGIN_ENABLED` environment variable to control network logging.
Note: To enable or disable network logging, add `DAPI_NETWORK_LOGGIN_ENABLED` flag to the environment variables and set the value to `YES` or `NO`. 
### Fixed
- Configurations extra headers, query params, and body. 

## 2.16.1 - 2021-07-12
### Fixed
- Update configurations.

## 2.16.0 - 2021-07-12
### Added
- An API call is serially queued, and considered completed once the MFA is resolved.

## 2.15.0 - 2021-07-09
### Fixed
- Fix `unrecognized selector sent to instance` for metadata transfer bounds.

## 2.14.0 - 2021-06-29
### Fixed
- Bank response fields are now optional.

## 2.13.0 - 2021-06-27
### Fixed
- Transaction object fields are now optional (nullable).

## 2.12.0 - 2021-06-22
This is an RC version of the SDK hopes to resolve points mentioned in Fixed section.
### Fixed
- Fix crash caused by CoreData being run on a background thread.

## 2.11.0 - 2021-06-17

### Added
- Get Cards API from cache `connection.cards`.

## 2.10.0 - 2021-06-16

### Added
- Get Cards API `connection.getCards(_: ([DapiCard]?, Error?, String?))`.
- Get Card Transactions API `connection.getTransactionsFor(_: DapiCard, from: Date, to: Date, completion: ([DapiTransaction]?, Error?, String?))`.

## 2.9.0 - 2021-06-06

### Fixed
- Accounts selection UI filters accounts of the passed connection.

### Added
- `connection.getConnectionParameters()` now returns a dictionary representation of the connection.
- `DapiBankConnection.create(_ connectionParameters: [String: Any])` to create a connection programmatically.

## 2.8.0 - 2021-05-26

### Fixed

- Caching accounts from the same bank account for different `clientUserID`.
- Crash caused by calling `getBeneficiaries` with an MFA. 

## 2.7.2 - 2021-05-22

### Fixed

- Removed comments.

## 2.7.1 - 2021-05-22

### Fixed

- MFA fields are fixed to handle multiple inputs.

## 2.7.0 - 2021-05-19

### Added

- `DapiBankConnection` has 3 new properties for bank logos: `fullLogo`, `halfLogo` and `miniLogo`.

### Fixed

- A crash occuring when opening transfer UI with bank connection has no accounts.
- `createTransfer` callback is fired with error when user taps on back button of transfer UI.

## 1.2.0 - 2020-12-29

### Changed

- `DapiClient` (`DPCClient`) now accepts `DapiConnectionDetails` (`DPCConnectionDetails`) instead of `userID`.
Now any request on `client` will be operated on the provided connection.

```
// Example - Swift
if let connection = self.client.connect.getConnections().first {
    self.client.connection = connection
}
```

```
// Example - Objective-C
self.client.connection = [self.client.connect getConnections].firstObject
```

- `DapiConnectDelegate` (`DPCConnectDelegate`) now returns `DapiConnectionDetails` upon a successful connection instead of `userID`.
- If you're using `DapiClient.instance`, now you can use `DapiClient.instances` which returns an array that you can filter to match your needs.


