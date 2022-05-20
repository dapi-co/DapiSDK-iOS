//
//  DPCCardBalance.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 6/16/21.
//  Copyright © 2021 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DapiCardBalance)
@interface DPCCardBalance : NSObject

@property (strong, nonatomic, nullable, readonly) NSNumber *amountDue;
@property (strong, nonatomic, nullable, readonly) NSNumber *availableBalance;
@property (strong, nonatomic, nullable, readonly) NSNumber *outstandingBalance;
@property (strong, nonatomic, nullable, readonly) NSDate *dueDate;

- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
