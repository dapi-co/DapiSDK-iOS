# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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


