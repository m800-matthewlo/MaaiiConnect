#import <Foundation/Foundation.h>


@interface NSString (NSString_Encrypt)
- (NSString *)encryptWithKey:(NSString*)key;
- (NSString *)decryptWithKey:(NSString*)key;
- (NSString *)encryptToHexadecimalWithKey:(NSString *)key;
@end
