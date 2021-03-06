//
//  utils.h
//  Appscript
//
//   Copyright (C) 2007-2008 HAS
//

#import <Foundation/Foundation.h>
#import <Carbon/Carbon.h>


NSString *AEMDescTypeToDisplayString(OSType code);
NSString *AEMObjectToDisplayString(NSObject *obj);

#define AEMIsDescriptorEqualToObject(desc, obj) ( \
		[obj isKindOfClass: [NSAppleEventDescriptor class]] \
		&& ([desc descriptorType] == [obj descriptorType]) \
		&& [[desc data] isEqualToData: [obj data]])


/**********************************************************************/
// supported by all self-packing objects

@protocol AEMSelfPackingProtocol

- (NSAppleEventDescriptor *)packWithCodecs:(id)codecs;

@end


/**********************************************************************/

@protocol AEMCodecsProtocol

- (NSAppleEventDescriptor *)pack:(id)obj;

- (NSAppleEventDescriptor *)applicationRootDescriptor;

- (id)unpack:(NSAppleEventDescriptor *)desc;

- (id)fullyUnpackObjectSpecifier:(NSAppleEventDescriptor *)desc;

@end

