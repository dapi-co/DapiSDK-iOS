//
//  DPCBankBeneficiary.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 4/25/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiBankBeneficiary)
@interface DPCBankBeneficiary : NSObject

@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *accountNumber;
@property (nonatomic, strong, nullable) NSString *iban;
@property (nonatomic, strong, nullable) NSString *type;
@property (nonatomic, strong, nullable) NSString *status;
@property (nonatomic, strong, nullable) NSString *accountID;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
