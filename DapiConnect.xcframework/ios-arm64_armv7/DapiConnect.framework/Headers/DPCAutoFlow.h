//
//  DPCAutoFlow.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 11/04/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCConnect.h"
#import "DPCPayment.h"
#import "Dapi.h"

NS_ASSUME_NONNULL_BEGIN
@protocol DPCConnectDelegate;
@protocol DPCAutoFlowDelegate;

NS_SWIFT_NAME(DapiAutoFlow)
@interface DPCAutoFlow : NSObject

/// The delegate of Connect callbacks.
@property (nonatomic, weak) id<DPCConnectDelegate> connectDelegate;

/// The delegate of AutoFlow callbacks.
@property (nonatomic, weak) id<DPCAutoFlowDelegate> autoflowDelegate;

/// Your userID.
@property (nonatomic, strong) DPCBankConnection *connection;

/// The maximum amount a user can enter to the numpad.
@property (nonatomic, assign) NSUInteger minimumAmount;

/// The minimum amount a user can enter to the numpad.
/// @discussion The default amount in the numpad will be this value.
@property (nonatomic, assign) NSUInteger maximumAmount;

- (instancetype)initWithConnection:(DPCBankConnection *)connection
                           account:(DPCAccount * __nullable)account
                            amount:(double)amount
                       beneficiary:(DPCBeneficiary *)beneficiary
                            remark:(NSString *)remark
                        completion:(void (^ __nullable)(DPCAccount *account,
                                                        double amount,
                                                        NSError *__nullable error,
                                                        OperationID *__nullable operationID,
                                                        ReferenceNumber *__nullable referenceNumber))completion;

- (instancetype)initWithConnection:(DPCBankConnection *)connection
                           account:(DPCAccount * __nullable)account
                            amount:(double)amount
                   wireBeneficiary:(DPCWireBeneficiary *)wireBeneficiary
                            remark:(NSString *)remark
                        completion:(void (^ __nullable)(DPCAccount *account,
                                                        double amount,
                                                        NSError *__nullable error,
                                                        OperationID *__nullable operationID,
                                                        ReferenceNumber *__nullable referenceNumber))completion;

- (instancetype)init __attribute__((unavailable("use initWithClientUserID:account:amount:beneficiary:completion:")));


/// Presents AutoFlow UI.
- (void)present;

/// Dismisses AutoFlow UI.
/// @param completion Called after the dismissal animation is completed.
- (void)dismissWithCompletion:(void (^ __nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
