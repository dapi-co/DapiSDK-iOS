//
//  DPCConfigurations.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 07/04/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *DPCEndPoint NS_TYPED_EXTENSIBLE_ENUM;

extern DPCEndPoint const DPCEndPointExchangeToken;
extern DPCEndPoint const DPCEndPointGetIdentity;
extern DPCEndPoint const DPCEndPointGetAccounts;
extern DPCEndPoint const DPCEndPointGetAccountMetadata;
extern DPCEndPoint const DPCEndPointGetBalance;
extern DPCEndPoint const DPCEndPointGetTransactions;
extern DPCEndPoint const DPCEndPointGetBeneficiaries;
extern DPCEndPoint const DPCEndPointCreateBeneficiary;
extern DPCEndPoint const DPCEndPointCreateTransfer;
extern DPCEndPoint const DPCEndPointCreateTransferToExistingBeneficiary;
extern DPCEndPoint const DPCEndPointResumeJob;
extern DPCEndPoint const DPCEndPointDelinkUser;
extern DPCEndPoint const DPCEndPointGetCards;

typedef NSString *DPCEnvironment NS_TYPED_EXTENSIBLE_ENUM;

extern DPCEnvironment const DPCEnvironmentProduction;
extern DPCEnvironment const DPCEnvironmentSandbox;

NS_SWIFT_NAME(DapiConfigurations)
@interface DPCConfigurations : NSObject

/*!
 @brief Supported countries for banks shown in connect.
 
 @discussion Country codes of supported countries. (ISO 3166-2 format).
*/
@property (nonatomic, copy, readonly) NSArray<NSString *> *countries;

/*!
 @brief Environment of the banks (either production or sandbox).
*/
@property (nonatomic, copy, readonly) DPCEnvironment environment;

/*!
 @brief Let's you set a custom end point. This only needed when not using the server-side SDK.
*/
@property (nonatomic, copy) NSDictionary<DPCEndPoint, NSString *> *endpoints;

@property (nonatomic, copy) NSDictionary<DPCEndPoint, NSArray<NSURLQueryItem *> *> *endPointExtraQueryItems;
@property (nonatomic, copy) NSDictionary<DPCEndPoint, NSDictionary<NSString *, NSString *> *> *endPointExtraHeaderFields;

/*!
 @brief Let's you append extra json object to the root of the body.
 
 @discussion The appended dictionary will be under the key "UserExtraBody" at the root JSON body. This will not work with all 'DPCEndPoint's since some of them are HTTP GET requests.
*/
@property (nonatomic, copy) NSDictionary<DPCEndPoint, NSDictionary<NSString *, id> *> *endPointExtraBody;

/*!
 @brief Controls whether bank account connect UI shows the bank logos.
 
 @discussion The value is true by default.
*/
@property (nonatomic, assign) BOOL showLogos;


/*!
 @brief Controls whether bank account connect UI shows a close button.
 
 @discussion The value is true by default.
*/
@property (nonatomic, assign) BOOL showCloseButton;

/*!
 @brief Controls whether account selection UI shows a add account button.
 
 @discussion The value is true by default.
*/
@property (nonatomic, assign) BOOL showAddAccountButton;

- (instancetype)initWithCountries:(NSArray<NSString *> *_Nullable)countries environment:(DPCEnvironment _Nullable)environment;
- (instancetype)init __attribute__((unavailable("use [DPCConfigurations initWithCountries:environment:];")));

@end

NS_ASSUME_NONNULL_END
