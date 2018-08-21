//
//  FKVPair.h
//  FastKV
//
//  Created by Yao Li on 2018/8/9.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, FKVPairType) {
    FKVPairTypeBOOL = 0,
    FKVPairTypeInt32,
    FKVPairTypeInt64,
    FKVPairTypeFloat,
    FKVPairTypeDouble,
    FKVPairTypeString,
    FKVPairTypeData,
};

@protocol FKVCoding <NSObject>
+ (id)parseFromData:(NSData *)data error:(NSError *__autoreleasing *)error;

- (NSData *)representationData;
@end

@interface FKVPair : NSObject <FKVCoding>

@property(assign, nonatomic) FKVPairType valueType;

@property(copy, nonatomic) NSString *objcType;

@property(copy, nonatomic) NSString *key;

@property(assign, nonatomic) BOOL boolVal;

@property(assign, nonatomic) int32_t int32Val;

@property(assign, nonatomic) int64_t int64Val;

@property(assign, nonatomic) float floatVal;

@property(assign, nonatomic) double doubleVal;

@property(copy, nonatomic) NSString *stringVal;

@property(copy, nonatomic) NSData *binaryVal;

@end

@interface FKVPairList : NSObject <FKVCoding>
@property(copy, nonatomic) NSMutableArray<FKVPair *> *items;
@end
