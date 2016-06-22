//
//  CRNPaymentViewController.h
//  CardRecognition
//
//  Created by Viktor Bespalov on 10/16/14.
//  Copyright (c) 2014 PayCards. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PCDPayment, PCDPaymentViewController;

/// PCDPaymentViewController delegate
@protocol PCDPaymentViewControllerDelegete <NSObject>
@optional

/// This is retrieved upon completion of the payment by the user or if an incorrect PCDPayment copy has been submitted.
- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
           didCompletePayment:(PCDPayment *)payment
                transactionId:(NSString *)transactionId
                        error:(NSError *)error;

/// Is fetched when the user interrupts payment by the back button
- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
             didCancelPayment:(PCDPayment *)payment;

/// In some cases a payment can be in processing for a long time. In this case, the following method is fetched
- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
didGetProccesingStateForPayment:(PCDPayment *)payment
                transactionId:(NSString *)transactionId
                        error:(NSError *)error;
@end

/// Root Card Scan View Controller
@interface PCDPaymentViewController : UINavigationController

/// Payment configuration
@property (nonatomic) PCDPayment *payment;

/**
 Present PaymentViewController
 
 @param viewController is the controller on which the payment screen will be displayed
 @param delegate enables the tracking of the payment status
 
 @return completion is a block that will be fetched upon completion of animation of the payment screen display
 */
+ (void)presentOnViewController:(UIViewController *)viewController
                        payment:(PCDPayment *)payment
                       delegate:(id<PCDPaymentViewControllerDelegete>)delegate
                     completion:(void (^)(void))completion;

- (void)presentOnViewController:(UIViewController *)viewController
                       delegate:(id)delegate
                     completion:(void (^)(void))completion;

/// Completion is a block that is retrieved after the framework screen was hidden
- (void)dismissWithCompletion:(void (^)(void))completion;

@end
