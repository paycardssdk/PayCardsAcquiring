//
//  CRNTransactionHistory.h
//  CardRecognition
//
//  Created by Viktor Bespalov on 10/16/14.
//  Copyright (c) 2014 PayCards. All rights reserved.
//
 
#import <Foundation/Foundation.h>

/**
 @description Possible payment transaction statuses
 
 @note Only PCDPaymentTransactionStatusSuccess and PCDPaymentTransactionStatusError statuses are final. All others are intermediate. If the obtained status was intermediate status request should be repeated.
 
 @param PCDPaymentTransactionStatusUnknown      This transaction status is unknown or was not received yet. In this case, check the error. If the error is missing, try to repeat status request
 @param PCDPaymentTransactionStatusCreated      This transaction has been created
 @param PCDPaymentTransactionStatusAuthRequired 3DS authentication is required for this transaction
 @param PCDPaymentTransactionStatusPending      This transaction is being processed
 @param PCDPaymentTransactionStatusSuccess      This transaction has been successfully completed
 @param PCDPaymentTransactionStatusError        This transaction has failed
 */
typedef NS_ENUM(int, PCDPaymentTransactionStatus)  {
    PCDPaymentTransactionStatusUnknown,
    PCDPaymentTransactionStatusCreated,
    PCDPaymentTransactionStatusAuthRequired,
    PCDPaymentTransactionStatusPending,
    PCDPaymentTransactionStatusSuccess,
    PCDPaymentTransactionStatusError,
};

/// If the payment is processing for a long time and the method is fetched, the application can display the final status with the use of PCDTransactionHistory
@interface PCDTransactionHistory : NSObject

/**
 Send request transaction status by transaction id
 
 @param transactionId
 
 @return the payment status of a transaction or payment errors
 */
+ (void)requestTransactionStatusByTransactionId:(NSString *)transactionId
                                     completion:(void(^)(PCDPaymentTransactionStatus status, NSError *error))completion;

@end
