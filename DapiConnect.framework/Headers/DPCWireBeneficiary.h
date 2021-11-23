//
//  DPCWireBeneficiaryAPI.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/28/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCLinesAddress.h"

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(DapiWireBeneficiary)

@interface DPCWireBeneficiary : NSObject

@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *firstName;
@property(nonatomic, copy) NSString *lastName;
@property(nonatomic, copy) NSString *nickname;

@property(nonatomic, copy) NSString *accountNumber;
@property(nonatomic, copy) NSString *routingNumber;
@property(nonatomic, copy) NSString *receiverAccountType;
@property(nonatomic, copy) NSString *receiverType;
@property (nonatomic, copy)  NSString *zipCode;

@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy)  NSString *state;
@property (nonatomic, copy)  NSString *city;
@property(nonatomic, copy) NSString *bankName;
@property (nonatomic, strong) DPCLinesAddress *linesAddress;
@property(nonatomic, copy) NSString* type;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;
- (NSDictionary<NSString *, id> *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END
