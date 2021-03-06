//
//  ApplePayProvision.h
//  Copyright (c) 2018 Abdalla Magdi Soliman
//

#import "Foundation/Foundation.h"
#import "Cordova/CDV.h"
#import <PassKit/PassKit.h>
#import <WatchConnectivity/WatchConnectivity.h>

typedef void (^ AddPaymentRequestCallbackType)(PKAddPaymentPassRequest *request);

@interface ApplePayProvision : CDVPlugin<PKAddPaymentPassViewControllerDelegate>

- (void) checkDeviceEligibility:(CDVInvokedUrlCommand*)command;
- (void) checkCardEligibility:(CDVInvokedUrlCommand*)command;
- (void) checkCardEligibilityBySuffix:(CDVInvokedUrlCommand*)command;
- (void) addCardToWallet:(CDVInvokedUrlCommand*)command;
- (void) sendPassRequestData:(CDVInvokedUrlCommand*)command;

- (NSString *)dataToHexString:(NSData *)data;

@property (nonatomic, strong) NSString* cachedCallbackId;
@property (nonatomic) AddPaymentRequestCallbackType addPaymentRequestCallback;

@end
