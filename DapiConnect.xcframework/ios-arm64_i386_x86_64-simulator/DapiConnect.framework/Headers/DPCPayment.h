//
//  DPCPayment.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/18/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import "DPCAPI.h"
#import "DPCBankBeneficiary.h"
#import "DPCBankWireBeneficiary.h"
#import "DPCWireBeneficiary.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiPayment)
@interface DPCPayment : DPCAPI

@property (nonatomic, copy, readonly) NSString *userID;

- (nullable instancetype)initWithUserID:(NSString *)userID clientUserID:(NSString *)clientUserID;
- (instancetype)init __attribute__((unavailable("use initWithUserID:clientUserID:")));


- (void)getBeneficiaries:(void (^ __nullable)(NSArray<DPCBankBeneficiary *> *__nullable beneficiaries, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)getWireBeneficiaries:(void (^ __nullable)(NSArray<DPCBankWireBeneficiary *> *__nullable beneficiaries, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)createBeneficiary:(DPCBeneficiary *)beneficiaryDetails completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)createWireBeneficiary:(DPCWireBeneficiary *)beneficiaryDetails completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, NSString *__nullable operationID))completion;


- (void)createTransferToExistingBeneficiaryFromAccount:(NSString *)accountID beneficiaryID:(NSString *)beneficiaryID amount:(double)amount remark:(NSString *__nullable)remark completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, OperationID *__nullable operationID))completion;

- (void)createWireTransferToExistingBeneficiaryFromAccount:(NSString *)accountID
                                             beneficiaryID:(NSString *)beneficiaryID
                                                    amount:(double)amount
                                                    remark:(NSString *__nullable)remark
                                                completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, OperationID *__nullable operationID))completion;
- (void)createTransferFromAccountID:(NSString *)accountID
                             amount:(double)amount
                      toBeneficiary:(DPCBeneficiary *)beneficiary
                             remark:(NSString *)remark
                         completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, OperationID *__nullable operationID))completion;
- (void)createWireTransferFromAccountID:(NSString *)accountID
                                 amount:(double)amount
                          toBeneficiary:(DPCWireBeneficiary *)wireBeneficiary
                                 remark:(NSString *)remark
                             completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, OperationID *__nullable operationID))completion;


@end

NS_ASSUME_NONNULL_END
