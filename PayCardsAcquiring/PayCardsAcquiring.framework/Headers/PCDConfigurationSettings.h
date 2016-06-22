//
//  PCDConfigurationSettings.h
//  CardRecognition
//
//  Created by Igor Pesin on 3/11/15.
//  Copyright (c) 2015 PayCards. All rights reserved.
//

/** 
 Combination of the elements of the following enum
 
 @param PCDRequiredCardFieldHolderName Holder Name
 @param PCDRequiredCardFieldExpireDate Expire Date
 @param PCDRequiredCardFieldCardName Card Name
 @param PCDRequiredCardFieldAll All fields
 */
typedef NS_OPTIONS(NSInteger, PCDRequiredCardFields) {
    PCDRequiredCardFieldHolderName = 1 << 0,
    PCDRequiredCardFieldExpireDate = 1 << 1,
    PCDRequiredCardFieldCardName = 1 << 2,
    PCDRequiredCardFieldAll = PCDRequiredCardFieldHolderName | PCDRequiredCardFieldExpireDate | PCDRequiredCardFieldCardName
    
};

