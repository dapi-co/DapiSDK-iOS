//
//  DPCBalance.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/21/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCPair.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiBalance)
@interface DPCBalance : NSObject

@property (nonatomic, strong, nullable) NSNumber *amount;
@property (nonatomic, strong, nullable) DPCPair *currency;
@property (nonatomic, strong, nullable) NSString *accountNumber;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;


@end

NS_ASSUME_NONNULL_END
