//
//  DPCAddress.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/21/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiAddress)
@interface DPCAddress : NSObject

@property (nonatomic, copy, nullable) NSString *flat;
@property (nonatomic, copy, nullable) NSString *building;
@property (nonatomic, copy, nullable) NSString *area;
@property (nonatomic, copy, nullable) NSString *poBox;
@property (nonatomic, copy, nullable) NSString *city;
@property (nonatomic, copy, nullable) NSString *state;
@property (nonatomic, copy, nullable) NSString *country;
@property (nonatomic, copy, nullable) NSString *full;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
