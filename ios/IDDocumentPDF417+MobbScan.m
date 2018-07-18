#import "IDDocumentPDF417+MobbScan.h"
#import "Distance+MobbScan.h"
#import <objc/runtime.h>

@implementation IDDocumentPDF417 (MobbScan)

- (NSDictionary *)dictionaryRepresentation {
    NSMutableDictionary *mutableDictionary = [[NSMutableDictionary alloc] init];
    Class class = [self class];
    while (class != [NSObject class]) {
        [mutableDictionary addEntriesFromDictionary:[self dictionaryRepresentationOfClass:class]];
        class = [class superclass];
    }
    return [NSDictionary dictionaryWithDictionary:mutableDictionary];
}

- (NSDictionary *)dictionaryRepresentationOfClass:(Class)class {
    unsigned int numberOfProperties = 0;
    objc_property_t *propertyList = class_copyPropertyList(class, &numberOfProperties);
    NSMutableDictionary *mutableDictionary = [[NSMutableDictionary alloc] initWithCapacity:numberOfProperties];
    for (unsigned int i = 0; i < numberOfProperties; i++) {
        NSString *key = [NSString stringWithUTF8String:property_getName(propertyList[i])];
        NSObject *value = [self valueForKey:key];
        if (value != nil) {
            if([key isEqualToString:@"distance"]){
                value = [(Distances*)value dictionaryRepresentation];
                [mutableDictionary setObject:value forKey:key];
            } else {
                [mutableDictionary setObject:[value description] forKey:key];
            }
        }
    }
    return mutableDictionary;
}

@end
