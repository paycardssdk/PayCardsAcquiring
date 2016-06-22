//
//  ViewController.swift
//  PayCardsAcquiringSwiftDemo
//
//  Created by Viktor Bespalov on 14/06/16.
//  Copyright © 2016 pay.cards. All rights reserved.
//

import UIKit
import PayCardsAcquiring

class ViewController: UIViewController, PCDPaymentViewControllerDelegete {
    
    // MARK: - IBOutlets: Views
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    // MARK: - Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
 
    // MARK: - IBActions
    
    @IBAction func presentPayCards(sender: AnyObject) {
        
        PCDConfiguration.sharedInstance().merchantId = "191238281216"
        
        //See QuickHelp
        
        let customer = PCDCustomer()
        customer.ID = "123456"
        customer.email = "customer@email.com"
        customer.phoneNumber = "+79998880000"
        customer.firstname = "John"
        customer.lastname = "Smith"
        
        let payment = PCDPayment()
        payment.amount = 1
        payment.currencyCode = .RUB
        payment.orderNumber = "\(arc4random_uniform(10000))"
        payment.orderDescription = "Descriptopn"
        
        payment.customer = customer
        
        activityIndicator.startAnimating()
        PCDPaymentViewController.presentOnViewController(self, payment: payment, delegate: self) { 
            self.activityIndicator.stopAnimating()
        }
    }
    
    // MARK: - PCDPaymentViewControllerDelegete
    
    func paymentViewController(paymentViewController: PCDPaymentViewController!, didCompletePayment payment: PCDPayment!, transactionId: String!, error: NSError!) {
        print("PAYMENT COMPLETE: transactionId - \(transactionId) / error: \(error.localizedDescription)")
        
        paymentViewController.dismissWithCompletion(nil)
    }
    
    func paymentViewController(paymentViewController: PCDPaymentViewController!, didCancelPayment payment: PCDPayment!) {
        print("PAYMENT CANCELED")
        
        paymentViewController.dismissWithCompletion(nil)
    }
    
    func paymentViewController(paymentViewController: PCDPaymentViewController!, didGetProccesingStateForPayment payment: PCDPayment!, transactionId: String!, error: NSError!) {
        print("TIMEOUT / transactionId - \(transactionId) / error - \(error.localizedDescription)")
        
        paymentViewController.dismissWithCompletion(nil)
    }
}

