#import "com/mobbeel/mobbscan/document/ita/idcard/parser/ITAIDCardMRZParser.h"
#import "com/mobbeel/mobbscan/document/ita/idcard/section/ITAIDCardMRZSection.h"
#import "com/mobbeel/mobbscan/document/IDDocumentImageFaceSection.h"
#import "com/mobbeel/mobbscan/service/ita/idcard/ITAIDCardDocumentService.h"
#import "MainDependencyInjector.h"

@interface MSITAIDCardDependencyInjector : NSObject

@property (nonatomic, strong) MSITAIDCardMRZParser *itaIDCardMRZParser;
@property (nonatomic, strong) MSITAIDCardMRZSection *itaIDCardMRZSection;
@property (nonatomic, strong) MSIDDocumentImageFaceSection *itaIDCardFaceImageSection;
@property (nonatomic, strong) MSITAIDCardDocumentService *itaIDCardDocumentService;

- (id)initWithMainDependencyInjector:(MainDependencyInjector*)mainDependencyInjector;

@end
