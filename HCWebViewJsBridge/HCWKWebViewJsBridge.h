//
//  HCWKJsBridge.h
//  Demo
//
//  Created by lhc on 2019/9/20.
//  Copyright © 2019 lhc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "HCWebViewJsBridgeUtil.h"

/**
 HCWKWebViewJsBridge is used to implement communication between H5 and WKWebView.
 Please refer to the README.md for detailed usage.
 
 js code example, hcJsBridge is a global object:
 1. H5 register an api for native calls
     hcJsBridge.registerHandler("test", function(data, callback) {
        callback(responseData);
     })
 
 2. H5 call a native api, api name is 'ui.alert'
     hcJsBridge.callHandler("ui.alert", data, function (responseData) {
 
     })
 */
@interface HCWKWebViewJsBridge : NSObject
/**
 Static constructor
 
 @param webView specified a WKWebView object
 @return HCWKWebViewJsBridge
 */
+ (instancetype _Nonnull)bridgeWithWebView:(WKWebView * _Nonnull)webView;

/// If hcJsBridge.js is not introduced in H5, you need to call the static constructor and enable is YES.
///
/// @param webView specified a WKWebView object
/// @param enable Default NO, If YES, the native will inject js into H5 and initialize hcjsbridge object.
+ (instancetype _Nonnull)bridgeWithWebView:(WKWebView * _Nonnull)webView injectJS:(BOOL)enable;

/**
 Add an class object to HCWKWebViewJsBridge with default namespace.
 This class object is used to implement the handler method of H5 calling native.
 
 @param apiObject implementation object of the H5 call native.
 */
- (void)addJsBridgeApiObject:(id _Nonnull)apiObject;

/**
 Add an class object to HCWKWebViewJsBridge with specified namespace.
 
 @param apiObject implementation object of the H5 call native.
 @param name namespace
 */
- (void)addJsBridgeApiObject:(id _Nonnull)apiObject namespace:(NSString * _Nullable)name;

/**
 Native call H5's already registered handler
 
 @param handlerName specified handler name
 @param data send data
 @param responseCallback callback block
 */
- (void)callHandler:(NSString * _Nonnull)handlerName
               data:(id _Nullable)data
   responseCallback:(HCJBResponseCallback _Nullable)responseCallback;

/**
 Native call H5's already registered handler
 
 @param handlerName specified handler name
 */
- (void)callHandler:(NSString * _Nonnull)handlerName;

/**
 Native call H5's already registered handler
 
 @param handlerName specified handler name
 @param data send data
 */
- (void)callHandler:(NSString * _Nonnull)handlerName
               data:(id _Nullable )data;

/**
 Native call H5's already registered handler
 
 @param handlerName specified handler name
 @param responseCallback callback block
 */
- (void)callHandler:(NSString * _Nonnull)handlerName
   responseCallback:(HCJBResponseCallback _Nullable)responseCallback;

/**
 Whether to enable the debug log mode.
 If it is YES, it will print some call process logs, but only print in DEBUG mode.
 
 @param debug Debug log switch
 */
- (void)enableDebugLogging:(BOOL)debug;

@end
