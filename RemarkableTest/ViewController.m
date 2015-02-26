//
//  ViewController.m
//  RemarkableTest
//
//  Created by Jason on 30/01/2015.
//  Copyright (c) 2015 Entropy. All rights reserved.
//

#import "ViewController.h"
#import "RemarkableSDK.framework/include/RemarkableSDK.h"

@interface ViewController ()

@property (nonatomic, strong) IBOutlet UIImageView * imageView;
@property (nonatomic, strong) IBOutlet UIButton * reloadBtn;

@end

@implementation ViewController
@synthesize imageView;
@synthesize reloadBtn;


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)reloadImage:(id)sender {
    
    NSDictionary * aboutObject = [[RemarkableManager sharedInstance] getRemarkableObjectForTitle:@"about"];
    
    NSString * imageURL = (NSString*) [aboutObject objectForKey:@"image"];
    NSLog(@"image url : %@", imageURL);
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(gotImage:) name:@"gotImage" object:nil];
    [[RemarkableManager sharedInstance] requestImageForURLString:imageURL withNotificationName:@"gotImage"];
    
}

-(void) gotImage:(NSNotification*)note {
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"gotImage" object:nil];
    if ([note.object isKindOfClass:[UIImage class]]) {
        UIImage * image = note.object;
        
        [imageView setImage:image];
        [imageView setContentMode:UIViewContentModeScaleAspectFit];
        
    }
    
}

@end
