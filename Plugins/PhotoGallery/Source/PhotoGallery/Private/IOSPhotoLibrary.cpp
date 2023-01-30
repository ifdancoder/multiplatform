// Fill out your copyright notice in the Description page of Project Settings.


#include "IOSPhotoLibrary.h"

#if PLATFORM_IOS

static FOnImageSelectedFromGallery ImageSelectedFromGalleryProxy;

@interface MyViewController()

@end

@implementation MyViewController

+ (MyViewController*)GetDelegate
{
	static MyViewController* Singleton = [[MyViewController alloc]init];
	return Singleton;
}

- (void)selectPhoto
{
	UIImagePickerController* picker = [[UIImagePickerController alloc]init];
	picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
	picker.delegate = self;
	[[IOSAppDelegate GetDelegate].IOSController presentViewController : picker animated : NO completion : nil];
}

+ (void)runSelectPhoto
{
	// perform this action on the iOS main thread
	[[MyViewController GetDelegate]
		performSelectorOnMainThread:@selector(selectPhoto) withObject:nil waitUntilDone
		: NO];
}

- (void)imagePickerController:(UIImagePickerController*)picker
didFinishPickingMediaWithInfo : (NSDictionary*)info
{

}

- (void)imagePickerController : (UIImagePickerController*)picker
didFinishPickingMediaWithInfo : (NSDictionary*)info
{
	_chosenImage = info[UIImagePickerControllerOriginalImage];
	NSData* data = UIImagePNGRepresentation(_chosenImage);
	uint8_t* bytes = (uint8_t*)data.bytes;
	TArray<uint8> UEBytes = TArray<uint8>(bytes, data.length);
	ImageSelectedFromGalleryProxy.ExecuteIfBound(UEBytes);
	[picker dismissViewControllerAnimated : YES completion : NULL] ;
}

@end

#endif

void IOSPhotoLibrary::OpenGallery()
{
#if PLATFORM_IOS
	ImageSelectedFromGalleryProxy = OnImageSelected;
	dispatch_async(dispatch_get_main_queue(),
		^ {
		[MyViewController runSelectPhoto] ;
		}
	);
#endif
}
