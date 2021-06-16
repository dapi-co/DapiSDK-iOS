//
//  DPCCard.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 6/16/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCPair.h"
#import "DPCCardBalance.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiCardStatus)
typedef NSString *DPCCardStatus NS_TYPED_EXTENSIBLE_ENUM;

extern DPCCardStatus const DPCCardStatusActive;
extern DPCCardStatus const DPCCardStatusDisabled;
extern DPCCardStatus const DPCCardStatusBlocked;

NS_SWIFT_NAME(DapiCard)
@interface DPCCard : NSObject

@property (copy, nonatomic, nonnull, readonly) NSString *cardNumber;
@property (copy, nonatomic, nonnull, readonly) NSString *name;
@property (copy, nonatomic, nonnull, readonly) NSString *cardID;
@property (copy, nonatomic, nonnull, readonly) NSString *type;
@property (copy, nonatomic, readonly) DPCCardStatus status;
@property (strong, nonatomic, nonnull, readonly) NSDate *expiryDate;
@property (strong, nonatomic, nonnull, readonly) NSNumber *creditLimit;
@property (strong, nonatomic, nonnull, readonly) DPCPair *currency;
@property (strong, nonatomic, nonnull, readonly) DPCCardBalance *balance;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
