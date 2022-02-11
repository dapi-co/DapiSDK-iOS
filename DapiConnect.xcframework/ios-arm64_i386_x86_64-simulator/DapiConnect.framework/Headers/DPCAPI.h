//
//  DPCAPI.h
//  DapiConnect
//
//  Created by Mohammed Ennabah on 7/19/20.
//  Copyright © 2020 Dapi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPCAccount.h"
#import "DPCBalance.h"
#import "DPCIdentity.h"
#import "DPCTransaction.h"
#import "DPCResult.h"
#import "DPCBankMetadata.h"
#import "DPCBeneficiary.h"
#import "DPCConfigurations.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString DPCOperationID;
@compatibility_alias OperationID DPCOperationID;

NS_SWIFT_NAME(DapiAPI)
@interface DPCAPI : NSObject

@end

NS_ASSUME_NONNULL_END
