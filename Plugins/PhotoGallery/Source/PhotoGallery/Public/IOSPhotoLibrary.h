#pragma once
#include "CoreMinimal.h"
#include "PhotoInterface.h"

#if PLATFORM_IOS

#import <UIKit/UIKit.h>

@interface MyViewController : UIViewController <UIImagePickerControllerDelegate,
												UINavigationControllerDelegate>

@property(nonatomic, retain)
UIImage* chosenImage;

+(void)runSelectPhoto;

@end

#endif

class PHOTOGALLERY_API IOSPhotoLibrary : public IPhotoGallery
{
public:
	virtual void OpenGallery() override;

};
