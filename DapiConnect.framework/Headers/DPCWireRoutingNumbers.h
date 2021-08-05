//
//  DPCWireRoutingNumbers.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/28/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPCWireRoutingNumbers : NSObject

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *value;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
