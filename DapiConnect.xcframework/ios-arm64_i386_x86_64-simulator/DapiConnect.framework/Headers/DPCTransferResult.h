//
//  DPCResult.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 3/23/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiTransferResult)
@interface DPCTransferResult: NSObject

@property (nonatomic, copy) NSString *operationID;
@property (nonatomic, copy,nullable) NSString *referenceNumber;
@property (nonatomic, copy,nullable) NSString *remark;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END

