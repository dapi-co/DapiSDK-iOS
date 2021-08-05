//
//  DPCWireBeneficiary.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/28/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCWireAddress.h"
#import "DPCWireRoutingNumbers.h"

NS_ASSUME_NONNULL_BEGIN

@interface DPCWireBeneficiary : NSObject

@property(nonatomic, copy) NSString *accountNumber;
@property(nonatomic, strong) DPCWireAddress *address;
@property(nonatomic, copy) NSString *bankName;
@property(nonatomic, copy) NSString *identifier;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, strong) DPCWireRoutingNumbers *routingNumbers;
@property(nonatomic, nullable, copy) id status;
@property(nonatomic, nullable, copy) id type;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
