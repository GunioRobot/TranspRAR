//
//  TranspRAR_Controller.h
//  TranspRAR
//
//  Created by Martin All�us on 2010-09-06.
//  Copyright 2010 Appcorn AB. All rights reserved.
//
#import <Cocoa/Cocoa.h>

@class GMUserFileSystem;
@class TranspRAR_Controller;

@interface TranspRAR_Controller : NSObject {
  GMUserFileSystem* fs_;
  TranspRAR_Controller* fs_delegate_;
}

- (void)showMountError:(NSError *)error;

@end
