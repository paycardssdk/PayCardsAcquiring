//
//  CRNConfiguration.h
//  CardRecognition
//
//  Created by Viktor Bespalov on 10/16/14.
//  Copyright (c) 2014 PayCards. All rights reserved.
//
 
#import <Foundation/Foundation.h>
#import "PCDConfigurationSettings.h"

/**
 PCDCulture specifies the language of the framework UI. The following cultures are available
 
 @param PCDCultureEN EN
 @param PCDCultureRU RU
 @param PCDCultureES ES
 @param PCDCultureFR FR
 @param PCDCultureIT IT
 @param PCDCulturePT PT
 @param PCDCultureUA UA
 @param PCDCultureZH ZH
 */
typedef NS_ENUM(NSInteger, PCDCulture) {
    PCDCultureEN,
    PCDCultureRU,
    PCDCultureES,
    PCDCultureFR,
    PCDCultureIT,
    PCDCulturePT,
    PCDCultureUA,
    PCDCultureZH
};

/// Allows user to configure framework. Includes the following settings
@interface PCDConfiguration : NSObject

/// PCDCulture specifies the language of the framework UI
@property (nonatomic) PCDCulture culture;

/// Merchant’s ID obtained after registration in Wallet One Checkout
@property (nonatomic, copy) NSString *merchantId;

/// SoundEnabled. YES by default.
@property (nonatomic, getter=isSoundEnabled) BOOL soundEnabled;

/// Indicates will the recognized card be saved. Cards's data is stored in iOS Keychain and can be used by the client with the same ClientId for future payments. YES by default.
@property (nonatomic, assign) BOOL saveCard;

/// Indicates will the card’s CVV be stored in iOS Keychain. For future payments, saved CVV can be obtained after entering passcode or Touch ID. YES by default.
@property (nonatomic, assign) BOOL storeCVV;

/// Indicates which fields (holder name, expiration date, card name) of the recognized card should be shown after the recognition. Default value is PCDRequiredCardFieldAll.
@property (nonatomic) PCDRequiredCardFields requeriedCardFields;

/// Custom processing server url
@property (nonatomic, copy) NSString *processingServerUrl;

+ (instancetype)sharedInstance;

@end
