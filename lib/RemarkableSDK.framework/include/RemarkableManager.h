//
//  REMObjectManager.h
//  RemarkableSDK
//
//  Created by Jason on 29/01/2015.
//  Copyright (c) 2015 Entropy Labs. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface RemarkableManager : NSObject

/*! @var Remarkable draft mode flag, set YES to retrieve draft data, set NO for live data. */
 
@property (nonatomic, assign) BOOL draftMode;


/*!
 * @discussion RemarkableManager singleton.
 */
+ (RemarkableManager *)sharedInstance;


/*!
 * @discussion Initialise the RemarkableSDK with your unique APIKey and AppID.
 * @param apiKey from Remarkable control panel e.g 9dEFfk.
 * @param appID from Remarkable control panel e.g. 334c5d2f855eb9e5dd449f13.
 */
-(void) initialiseWithApiKey:(NSString *)apiKey withAppID:(NSString *)appID;

/*!
 * @discussion Add call to method in applicationDidEnterBackground: to release data objects and drop threads.
 */
-(void) handleApplicationToBackground;

/*!
 * @discussion Add call to method in applicationWillEnterForeground: to resume threads and rebuild data objects.
 */
-(void) handleApplicationToForeground;

/*!
 * @discussion Add call to method in applicationWillEnterForeground: to resume threads and rebuild data objects with option to receive notification when data has been refreshed from Remarkable server.
 */
-(void) handleApplicationToForegroundWithNotification:(NSString*)notificationName;

/*!
 * @discussion Check for latest version of data and retrieve if newer content exists.
 */
-(void) refreshAllObjects;

/*!
 * @discussion Get a Remarkable Object Dictionary by title name.
 * @param title as set in Remarkable control panel.
 * @return NSDictionary with all the properties of the object set in Remarkable control panel
 */
-(NSDictionary*) getRemarkableObjectForTitle:(NSString*)title;

/*!
 * @discussion Get an image for the given URL, this image may already be cached, if not it will be retrieved. The image is returned in the notification object.
 */
-(void) requestImageForURLString:(NSString*)urlString withNotificationName:(NSString*)notificationName;


//-(void) testSchemaManager;

@end
