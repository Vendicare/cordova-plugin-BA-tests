#import "com/mobbeel/mobbscan/document/hrv/idcard/parser/HRVIDCardMRZParser.h"
#import "com/mobbeel/mobbscan/document/hrv/idcard/section/HRVIDCardMRZSection.h"
#import "com/mobbeel/mobbscan/document/IDDocumentImageFaceSection.h"
#import "com/mobbeel/mobbscan/service/hrv/idcard/HRVIDCardDocumentService.h"
#import "MainDependencyInjector.h"

@interface MSHRVIDCardDependencyInjector : NSObject

@property (nonatomic, strong) MSHRVIDCardMRZParser *hrvIDCardMRZParser;
@property (nonatomic, strong) MSHRVIDCardMRZSection *hrvIDCardMRZSection;
@property (nonatomic, strong) MSIDDocumentImageFaceSection *hrvIDCardFaceImageSection;
@property (nonatomic, strong) MSHRVIDCardDocumentService *hrvIDCardDocumentService;

- (id)initWithMainDependencyInjector:(MainDependencyInjector*)mainDependencyInjector;

@end
