/*
 * Copyright @ 2019-present 8x8, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "JitsiMeetUserInfo.h"


@interface JitsiMeetConferenceOptionsBuilder : NSObject

/**
 * Server where the conference should take place.
 */
@property (nonatomic, copy, nullable) NSURL *serverURL;
/**
 * Room name.
 */
@property (nonatomic, copy, nullable) NSString *room;
/**
 * JWT token used for authentication.
 */
@property (nonatomic, copy, nullable) NSString *token;
/**
 * WEHAGO User AuthInformation.
 */
@property (nonatomic, copy, nullable) NSString *userAuth;
/**
 * WEHAGO Conference token used for Conference Enterance.
 */
@property (nonatomic, copy, nullable) NSString *joinCode;
/**
 * WEHAGO Deployed Services .
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *deployedServices;
/**
 * WEHAGO Conference call type - 1: 음성전화,  2: 화상전화, 3: 화상회의
 */
@property (nonatomic, copy, nullable) NSNumber *callType;
/**
 * WEHAGO Conference ExternalUserName
 */
@property (nonatomic, copy, nullable) NSString *externalUserName;

@property (nonatomic, assign) BOOL isSDK;

/**
 * Feature flags. See: https://github.com/jitsi/jitsi-meet/blob/master/react/features/base/flags/constants.js
 */
@property (nonatomic, readonly, nonnull) NSDictionary *featureFlags;

@property (nonatomic, readonly, nonnull) NSDictionary *config;

/**
 * Information about the local user. It will be used in absence of a token.
 */
@property (nonatomic, nullable) JitsiMeetUserInfo *userInfo;

- (void)setFeatureFlag:(NSString *_Nonnull)flag withBoolean:(BOOL)value;
- (void)setFeatureFlag:(NSString *_Nonnull)flag withValue:(id _Nonnull)value;

- (void)setConfigOverride:(NSString *_Nonnull)config withBoolean:(BOOL)value;
- (void)setConfigOverride:(NSString *_Nonnull)config withValue:(id _Nonnull)value;
- (void)setConfigOverride:(NSString *_Nonnull)config withDictionary:(NSDictionary * _Nonnull)dictionary;
- (void)setConfigOverride:(NSString *_Nonnull)config withArray:( NSArray * _Nonnull)array;

- (void)setAudioOnly:(BOOL)audioOnly;
- (void)setAudioMuted:(BOOL)audioMuted;
- (void)setVideoMuted:(BOOL)videoMuted;
- (void)setCallHandle:(NSString *_Nonnull)callHandle;
- (void)setCallUUID:(NSUUID *_Nonnull)callUUID;
- (void)setSubject:(NSString *_Nonnull)subject;

@end

@interface JitsiMeetConferenceOptions : NSObject

@property (nonatomic, copy, nullable, readonly) NSURL *serverURL;

@property (nonatomic, copy, nullable, readonly) NSString *room;
@property (nonatomic, copy, nullable, readonly) NSString *token;

@property (nonatomic, copy, nullable, readonly) NSString *userAuth;
@property (nonatomic, copy, nullable, readonly) NSString *joinCode;
@property (nonatomic, copy, nullable, readonly) NSArray<NSString *> *deployedServices;
@property (nonatomic, copy, nullable, readonly) NSNumber *callType;
@property (nonatomic, copy, nullable, readonly) NSString *externalUserName;
@property (nonatomic, assign, readonly) BOOL isSDK;

@property (nonatomic, readonly, nonnull) NSDictionary *featureFlags;

@property (nonatomic, nullable) JitsiMeetUserInfo *userInfo;

+ (instancetype _Nonnull)fromBuilder:(void (^_Nonnull)(JitsiMeetConferenceOptionsBuilder *_Nonnull))initBlock;
- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
