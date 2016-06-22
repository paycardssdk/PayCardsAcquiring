//
//  ViewController.m
//  PayCardsAcquiringObjcDemo
//
//  Created by Viktor Bespalov on 14/06/16.
//  Copyright © 2016 pay.cards. All rights reserved.
//

#import "ViewController.h"
#import <PayCardsAcquiring/PayCardsAcquiring.h>

@interface ViewController () <PCDPaymentViewControllerDelegete>

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;

@end

@implementation ViewController

#pragma mark - Lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - IBActions

- (IBAction)presentPayCards:(id)sender {
    
    //See QuickHelp
    
    PCDCustomer *customer = [PCDCustomer new];
    customer.ID = @"";
    customer.email = @"";
    customer.phoneNumber = @"";
    customer.firstname = @"";
    customer.lastname = @"";
    
    PCDPayment *payment = [PCDPayment new];
    payment.amount = @(1);
    payment.currencyCode = PCDCurrencyCodeRUB;
    payment.orderNumber = @"";
    payment.orderDescription = @"";
    
    payment.customer = customer;
    
    [_activityIndicator startAnimating];
    [PCDPaymentViewController presentOnViewController:self payment:payment delegate:self completion:^{
        [_activityIndicator stopAnimating];
    }];
}

#pragma mark - PCDPaymentViewControllerDelegete

- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
           didCompletePayment:(PCDPayment *)payment
                transactionId:(NSString *)transactionId
                        error:(NSError *)error {
    NSLog(@"PAYMENT COMPLETE: transactionId - %@ / error: %@", transactionId, error.localizedDescription);
    
    [paymentViewController dismissWithCompletion:nil];
}

- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
             didCancelPayment:(PCDPayment *)payment {
    NSLog(@"PAYMENT CANCELED");
    
    [paymentViewController dismissWithCompletion:nil];
}

- (void)paymentViewController:(PCDPaymentViewController *)paymentViewController
didGetProccesingStateForPayment:(PCDPayment *)payment
                transactionId:(NSString *)transactionId
                        error:(NSError *)error {
    NSLog(@"TIMEOUT / transactionId - %@ / error - %@", transactionId, error.localizedDescription);
    
    [paymentViewController dismissWithCompletion:nil];
}

@end
