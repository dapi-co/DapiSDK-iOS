//
//  DPCWireAddress.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/28/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCPair.h"

NS_ASSUME_NONNULL_BEGIN

@interface DPCWireAddress : NSObject

@property (nonatomic, copy)           NSString *city;
@property (nonatomic, copy)         NSString *country;
@property (nonatomic, copy)           NSString *full;
@property (nonatomic, nullable, copy) NSString * poBox;
@property (nonatomic, copy)           NSString *state;
@property (nonatomic, copy)           NSString *zipCode;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
