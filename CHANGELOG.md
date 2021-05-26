# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to
[Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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


