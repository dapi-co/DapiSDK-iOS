//
//  DPCTransaction.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/22/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCBrandDetails.h"
#import "DPCPair.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiTransaction)
@interface DPCTransaction : NSObject

@property (nonatomic, strong, nullable) NSNumber *beforeAmount;
@property (nonatomic, strong, nullable) NSNumber *afterAmount;
@property (nonatomic, strong, nullable) NSNumber *amount;
@property (nonatomic, strong, nullable) DPCPair *currency;
@property (nonatomic, strong, nullable) NSDate *date;
@property (nonatomic, copy, nullable) NSString *transactionDescription;
@property (nonatomic, copy, nullable) NSString *details;
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *category;
@property (nonatomic, copy, nullable) NSString *reference;
@property (nonatomic, strong, nullable) DPCBrandDetails *brandDetails;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
