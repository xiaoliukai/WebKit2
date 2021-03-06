/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WKPageFormClient_h
#define WKPageFormClient_h

#include <WebKit/WKBase.h>

#ifdef __cplusplus
extern "C" {
#endif

// Form Client.
typedef void (*WKPageWillSubmitFormCallback)(WKPageRef page, WKFrameRef frame, WKFrameRef sourceFrame, WKDictionaryRef values, WKTypeRef userData, WKFormSubmissionListenerRef listener, const void* clientInfo);

typedef struct WKPageFormClientBase {
    int                                                                 version;
    const void *                                                        clientInfo;
} WKPageFormClientBase;

typedef struct WKPageFormClientV0 {
    WKPageFormClientBase                                                base;

    // Version 0.
    WKPageWillSubmitFormCallback                                        willSubmitForm;
} WKPageFormClientV0;

enum { kWKPageFormClientCurrentVersion WK_ENUM_DEPRECATED("Use an explicit version number instead") = 0 };
typedef struct WKPageFormClient {
    int                                                                 version;
    const void *                                                        clientInfo;

    // Version 0.
    WKPageWillSubmitFormCallback                                        willSubmitForm;
} WKPageFormClient WK_DEPRECATED("Use an explicit versioned struct instead");

#ifdef __cplusplus
}
#endif

#endif // WKPageFormClient_h
