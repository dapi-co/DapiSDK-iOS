//
//  DPCBrandDetails.h
//  DapiConnect
//
//  Created by Abdelrahman Rizq on 10/10/2022.
//  Copyright © 2022 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiBrandDetails)
@interface DPCBrandDetails : NSObject

@property (nonatomic, strong, nullable) NSString *logo;
@property (nonatomic, strong, nullable) NSString *name;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
