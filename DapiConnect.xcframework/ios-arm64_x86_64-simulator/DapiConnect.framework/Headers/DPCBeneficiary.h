//
//  DPCBeneficiaryInfo.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 29/03/2020.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCLinesAddress.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *DPCBeneficiaryType NS_TYPED_EXTENSIBLE_ENUM;

extern DPCBeneficiaryType const DPCBeneficiaryTypeSame;
extern DPCBeneficiaryType const DPCBeneficiaryTypeLocal;
extern DPCBeneficiaryType const DPCBeneficiaryTypeInternational;

NS_SWIFT_NAME(DapiBeneficiary)
@interface DPCBeneficiary : NSObject

@property (nonatomic, strong, nullable) DPCLinesAddress *linesAddress;
@property (nonatomic, copy, nullable) NSString *accountNumber;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *bankName;
@property (nonatomic, copy, nullable) NSString *swiftCode;
@property (nonatomic, copy, nullable) NSString *iban;
@property (nonatomic, copy, nullable) NSString *phoneNumber;
@property (nonatomic, copy, nullable) NSString *country;
@property (nonatomic, copy, nullable) NSString *branchAddress;
@property (nonatomic, copy, nullable) NSString *branchName;
@property (nonatomic, copy, nullable) NSString *nickname;
@property (nonatomic, copy, nullable) DPCBeneficiaryType type;

- (NSDictionary<NSString *, id> *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END
