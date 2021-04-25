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

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong, nullable) NSString *accountNumber;
@property (nonatomic, strong, nullable) NSString *iban;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSString *accountID;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
