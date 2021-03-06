//
//  DPCNumber.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/22/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiNumber)
@interface DPCNumber : NSObject

@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *value;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
