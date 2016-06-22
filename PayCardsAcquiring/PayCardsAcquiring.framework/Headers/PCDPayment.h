//
//  CRNPayment.h
//  CardRecognition
//
//  Created by Viktor Bespalov on 10/16/14.
//  Copyright (c) 2014 PayCards. All rights reserved.
//
 
#import <Foundation/Foundation.h>
#import "PCDCustomer.h"

/**
 Payment currency. Supported currencies:
 
 @param PCDCurrencyCodeUSD USD
 @param PCDCurrencyCodeEUR EUR
 @param PCDCurrencyCodeKZT KZT
 @param PCDCurrencyCodeZAR ZAR
 @param PCDCurrencyCodeTJS TJS
 @param PCDCurrencyCodeBYR BYR
 @param PCDCurrencyCodeUAH UAH
 @param PCDCurrencyCodeRUB RUB
 */
typedef NS_ENUM(int, PCDCurrencyCode) {
    PCDCurrencyCodeRUB = 643,
    PCDCurrencyCodeKZT = 398,
    PCDCurrencyCodeZAR = 710,
    PCDCurrencyCodeUSD = 840,
    PCDCurrencyCodeTJS = 972,
    PCDCurrencyCodeBYR = 974,
    PCDCurrencyCodeEUR = 978,
    PCDCurrencyCodeUAH = 980,
    PCDCurrencyCodeGEL = 981,
    PCDCurrencyCodePLN = 985
};

/**
 Payment configuration
 
 @attention All the fields are mandatory
 */
@interface PCDPayment : NSObject

/// The order identifier in the merchant’s e-shop record-keeping system. The value of this parameter must be unique for each order. The order identifier must be unique for all the application instances.
@property (nonatomic, copy) NSString *orderNumber;

/// Order description
@property (nonatomic, copy) NSString *orderDescription;

/// The sum, without the merchant’s commission
@property (nonatomic, copy) NSNumber *amount;

/// Payment currency
@property (nonatomic) PCDCurrencyCode currencyCode;

/// Customer's settings
@property (nonatomic) PCDCustomer *customer;

@end
