//
//  DPCAccount.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/18/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCPair.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiAccount)
@interface DPCAccount : NSObject

@property (nonatomic, strong, nullable) NSString *iban;
@property (nonatomic, strong, nullable) NSString *number;
@property (nonatomic, strong, nullable) DPCPair *currency;
@property (nonatomic, strong, nullable) NSString *type;
@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *accountID;
@property (nonatomic, assign) double balance;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
