# RemarkableSDK-Sample
Sample App showing use of the RemarkableSDK

RemarkableSDK Usage
Initialisation
Import the header from the framework:
#import "RemarkableSDK.framework/include/RemarkableSDK.h"

If you wish to use the draft mode of Remarkable, set the draftMode flag before you make the call to initialiseWithApiKey in your appDelegate implementation like so:
[RemarkableManager sharedInstance].draftMode = YES;
Draft mode is false by default so you need only override if you are testing.

Initialise the framework with your APIKey and AppID, e.g.:
[[RemarkableManager sharedInstance] initialiseWithApiKey: @"<yourAPIKey>" withAppID:@"<yourAppID>"];
Typically this is set in your application:application didFinishLaunchingWithOptions: method. 

You can optionally handle app events when entering background or becoming active again through the methods:
[[RemarkableManager sharedInstance] handleApplicationToBackground];
[[RemarkableManager sharedInstance] handleApplicationToForeground];
Simply add those method calls to the respective methods in your appDelegate implementation:
applicationDidEnterBackground and applicationWillEnterForeground.

 
Object Usage
Remarkable Objects are delivered in an NSDictionary object for ease of integration.
You will need to know the name of the object as defined in the Remarkable Dashboard and the object can be accessed like so:
NSDictionary * anObject = [[RemarkableManager sharedInstance] getRemarkableObjectForTitle:@"objectName"];
Object properties are accessed in the standard key/value pair methods of NSDictionary.
NSString * imageURL = (NSString*) [anObject objectForKey:@"image"];
Images can be prefetched and are cached until required. To fetch an image whether it has been cached or not just call the method requestImageForURLString, passing the URL of the image as retrieved from the NSDictionary and, optionally, the string of an NSNotification name. Images are returned in an NSNotification object’s notification.object if the NSNotification name was not nil.
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(yourImageHandler:) name:@"yourNotification" object:nil];
[[RemarkableManager sharedInstance] requestImageForURLString:imageURL withNotificationName:@"yourNotification"];
Although the RemarkableSDK handles refreshing of your objects automatically once per session of activity, you can manually request objects to be refreshed, which will also prefetch any images which have not already been cached using the following method:
[[RemarkableManager sharedInstance] refreshAllObjects];


