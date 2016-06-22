//
//  PCDCustomer.h
//  CardRecognition
//
//  Created by Viktor Bespalov on 26/11/15.
//  Copyright © 2015 PayCards. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Customer's settings
@interface PCDCustomer : NSObject

/// A mandatory field, which identifies the end user in the merchant’s record-keeping system. The framework uses this parameter to determine which bank cards should be loaded from the server and shown to the user.
@property (nonatomic, copy) NSString *ID;

/// First name customer’s
@property (nonatomic, copy) NSString *firstname;

/// Last name customer’s
@property (nonatomic, copy) NSString *lastname;

/// Email customer’s. The user’s phone number or email should be provided
@property (nonatomic, copy) NSString *email;

/// Phone number customer’s. The user’s phone number or email should be provided
@property (nonatomic, copy) NSString *phoneNumber;

@end
