//
//  DPCBankConnection.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 22/06/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCAccount.h"
#import "DPCIdentity.h"
#import "DPCBankMetadata.h"
#import "DPCTransaction.h"
#import "DPCResult.h"
#import "DPCBankBeneficiary.h"
#import "DPCCard.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiBankConnection)
@interface DPCBankConnection : NSObject

typedef void (^TransferBlock)(DPCAccount *__nullable account, double amount, NSError *__nullable error, NSString *__nullable operationID);

@property (nonnull, nonatomic, copy, readonly) NSString *userID;
@property (nonnull, nonatomic, copy, readonly) NSString *clientUserID;
@property (nonnull, nonatomic, copy, readonly) NSString *bankID;
@property (nonnull, nonatomic, copy, readonly) NSString *swiftCode;
@property (nonnull, nonatomic, copy, readonly) NSString *bankName;
@property (nonnull, nonatomic, copy, readonly) NSString *countryName;
@property (nonnull, nonatomic, copy, readonly) NSString *fullLogo;
@property (nonnull, nonatomic, copy, readonly) NSString *halfLogo;
@property (nonnull, nonatomic, copy, readonly) NSString *miniLogo;
@property (nonatomic, copy, readonly) NSArray<DPCAccount *> *accounts;
@property (nonatomic, copy, readonly) NSArray<DPCCard *> *cards;
@property (nonatomic, strong, readonly) NSDate *createdAt;

+ (NSArray<DPCBankConnection *> *)getConnectionsWithClientUserID:(NSString *)clientUserID;

+ (void)create:(NSDictionary<NSString *, id> *)connectionParameters completion:(void (^ __nullable)(DPCBankConnection *__nullable connection, NSError *__nullable error))completion;

- (NSDictionary<NSString *, id> *)getConnectionParameters;

- (void)getAccountMetadata:(void (^ __nullable)(DPCBankMetadata *__nullable accounts, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)getIdentity:(void (^ __nullable)(DPCIdentity *__nullable identity, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)getAccounts:(void (^ __nullable)(NSArray<DPCAccount *> *__nullable accounts, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)getTransactionsForAccount:(DPCAccount *)account
                         fromDate:(NSDate *)fromDate
                           toDate:(NSDate *)toDate
                       completion:(void (^ __nullable)(NSArray<DPCTransaction *> *__nullable transactions, NSError *__nullable error, NSString*__nullable operationID))completion;

- (void)getTransactionsForCard:(DPCCard *)card
               fromDate:(NSDate *)fromDate
                 toDate:(NSDate *)toDate
             completion:(void (^ __nullable)(NSArray<DPCTransaction *> *__nullable transactions, NSError *__nullable error, NSString*__nullable operationID))completion;


- (void)getBeneficiaries:(void (^ __nullable)(NSArray<DPCBankBeneficiary *> *__nullable beneficiaries, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)createBeneficiary:(DPCBeneficiary *)beneficiaryDetails
                       completion:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error, NSString *__nullable operationID))completion;

- (void)createTransferToExistingBeneficiaryFromAccount:(DPCAccount *)account beneficiaryID:(NSString *)beneficiaryID amount:(double)amount remark:(NSString *__nullable)remark completion:(TransferBlock)completion;

- (void)createTransfer:(void (^ __nullable)(DPCAccount *account, double amount, NSError *__nullable error, NSString *__nullable operationID))completion;


- (void)createTransferFromAccount:(DPCAccount *__nullable)account
                       completion:(TransferBlock)completion;

- (void)createTransferToBeneficiary:(DPCBeneficiary *__nullable)beneficiary
                         completion:(TransferBlock)completion;

- (void)createTransferFromAccount:(DPCAccount *__nullable)account
                    toBeneficiary:(DPCBeneficiary *__nullable)beneficiary
                       completion:(TransferBlock)completion;

- (void)createTransferFromAccount:(DPCAccount *__nullable)account
                           amount:(double)amount
                       completion:(TransferBlock)completion;

- (void)createTransferFromAccount:(DPCAccount *__nullable)account
                    toBeneficiary:(DPCBeneficiary *__nullable)beneficiary
                           amount:(double)amount
                       completion:(TransferBlock)completion;

- (void)createTransferFromAccount:(DPCAccount *__nullable)account
                    toBeneficiary:(DPCBeneficiary *__nullable)beneficiary
                           amount:(double)amount
                           remark:(NSString *__nullable)remark
                       completion:(TransferBlock)completion;

- (void)delete:(void (^ __nullable)(DPCResult *__nullable result, NSError *__nullable error))completion;

- (void)getCards:(void (^ __nullable)(NSArray<DPCCard *> *__nullable result, NSError *__nullable error, NSString *__nullable operationID))completion;

@end

NS_ASSUME_NONNULL_END
