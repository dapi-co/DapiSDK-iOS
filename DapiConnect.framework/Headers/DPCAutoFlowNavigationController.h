//
//  DPCAutoFlowNavigationController.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 01/04/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPCConnect.h"
#import "DPCPayment.h"
#import "DPCSubaccount+CoreDataClass.h"

NS_ASSUME_NONNULL_BEGIN

@class DPCAutoFlowNavigationController;

@protocol DPCAutoFlowNavigationControllerDelegate <NSObject>

- (void)autoflowNavigationController:(DPCAutoFlowNavigationController *)autoFlowNavigationController willTransferAmount:(double)amount fromAccount:(DPCAccount *)senderAccount;
- (void)autoflowNavigationController:(DPCAutoFlowNavigationController *)autoFlowNavigationController beneficiaryInfoForBankWithID:(NSString *)bankID senderAccount:(DPCSubaccount *)subaccount beneficiaryInfo:(void (^)(DPCBeneficiary *_Nullable beneficiaryInfo))info;

- (void)autoflowNavigationController:(DPCAutoFlowNavigationController *)autoFlowNavigationController
    wireBeneficiaryInfoForBankWithID:(NSString *)bankID
                       senderAccount:(DPCSubaccount *)subaccount
                 wireBeneficiaryInfo:(void (^)(DPCWireBeneficiary *_Nullable wireBeneficiaryInfo))info;

- (void)autoflowNavigationController:(DPCAutoFlowNavigationController *)autoFlowNavigationController didSuccessfullyTransferAmount:(double)amount fromAccount:(DPCSubaccount *)senderSubaccount toAccuntID:(NSString *)recipientAccountID;
- (void)autoflowNavigationController:(DPCAutoFlowNavigationController *)autoFlowNavigationController didFailToTransferFromAccount:(DPCSubaccount *)senderSubaccount toAccuntID:(NSString * _Nullable)recipientAccountID withError:(NSError *)error;

@end

@interface DPCAutoFlowNavigationController : UINavigationController

@property (nonatomic, weak) id<DPCConnectDelegate> connectDelegate;
@property (nonatomic, weak) id<DPCAutoFlowNavigationControllerDelegate> autoFlowNavigationControllerDelegate;
@property (nonatomic, strong, readonly) DPCBankConnection *connection;
@property (nonatomic, assign) NSUInteger minimumAmount;
@property (nonatomic, assign) NSUInteger maximumAmount;

- (instancetype)initWithConnection:(DPCBankConnection *)connection account:(DPCAccount *)account amount:(double)amount beneficiary:(DPCBeneficiary *)beneficiary remark:(NSString *)remark completion:(void (^ __nullable)(DPCAccount *account, double amount, NSError *__nullable error, OperationID *__nullable operationID,NSString *__nullable referenceNumber))completion;

- (instancetype)initWithConnection:(DPCBankConnection *)connection
                           account:(DPCAccount *)account
                            amount:(double)amount
                       wireBeneficiary:(DPCWireBeneficiary *)wireBeneficiary
                            remark:(NSString *)remark
                        completion:(void (^ __nullable)(DPCAccount *account, double amount, NSError *__nullable error, OperationID *__nullable operationID,NSString *__nullable referenceNumber))completion;

- (instancetype)init __attribute__((unavailable("use initWithConnection:account:amount:beneficiary:completion:")));

@end

NS_ASSUME_NONNULL_END
