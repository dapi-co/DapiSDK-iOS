//
//  DPCWireBeneficiary.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/28/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCWireAddress.h"

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(DapiBankWireBeneficiary)
@interface DPCBankWireBeneficiary : NSObject

@property(nonatomic, copy) NSString *accountNumber;
@property(nonatomic, strong) DPCWireAddress *address;
@property(nonatomic, copy) NSString *bankName;
@property(nonatomic, copy) NSString *accountID;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *routingNumber;
@property(nonatomic, nullable, copy) id status;
@property(nonatomic, nullable, copy) id type;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;
- (NSDictionary<NSString *, id> *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END
