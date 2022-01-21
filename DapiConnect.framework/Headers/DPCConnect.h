//
//  DPCConnect.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 30/03/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPCBeneficiary.h"
#import "DPCConfigurations.h"
#import "DPCBankConnection.h"
#import "Dapi.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DPCConnectDelegate;

NS_SWIFT_NAME(DapiConnect)
@interface DPCConnect : NSObject

@property (nonatomic, weak) id<DPCConnectDelegate> delegate;
@property (nonatomic, copy) NSString *clientUserID;

- (instancetype)initWithClientUserID:(NSString *)clientUserID;
- (instancetype)init __attribute__((unavailable("use initWithClientUserID:")));


/// Presents Connect UI.
- (void)presentWithBankID:(NSString *)bankID;

/// Dismisses connect UI.
/// @param completion Called after the dismissal animation is completed.
- (void)dismissWithCompletion:(void (^ __nullable)(void))completion;


/// The connected bank accounts.
/// @discussion Returns all connections. For instance, details will include subaccounts, bankID, name and more. The returned userIDs are filtered by the clientUserID.
- (NSArray<DPCBankConnection *> *)getConnections;

@end

NS_ASSUME_NONNULL_END
