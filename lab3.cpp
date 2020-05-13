#include "lab3.h"
#include <windows.h>
#include <iostream>

#define THREAD_COUNT 11

HANDLE hThread[THREAD_COUNT];
DWORD ThreadID;
HANDLE hMutex;
HANDLE hSemaphoreB, hSemaphoreII, hSemaphoreF, hSemaphoreHH, hSemaphoreBFHI, hSemaphoreK, hSemaphoreH, hSemaphoreI;

unsigned int lab3_thread_graph_id() {
    return 18;
}

const char *lab3_unsynchronized_threads() {
    return "bcdi";
}

const char *lab3_sequential_threads() {
    return "khi";
}

DWORD WINAPI thread_a(LPVOID lpParam); // 0
DWORD WINAPI thread_b(LPVOID lpParam); // 1
DWORD WINAPI thread_c(LPVOID lpParam); // 2
DWORD WINAPI thread_d(LPVOID lpParam); // 3
DWORD WINAPI thread_e(LPVOID lpParam); // 4
DWORD WINAPI thread_f(LPVOID lpParam); // 5
DWORD WINAPI thread_g(LPVOID lpParam); // 6
DWORD WINAPI thread_h(LPVOID lpParam); // 7
DWORD WINAPI thread_i(LPVOID lpParam); // 8
DWORD WINAPI thread_k(LPVOID lpParam); // 9
DWORD WINAPI thread_m(LPVOID lpParam); // 10

DWORD WINAPI thread_a(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "a" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    ReleaseSemaphore(hSemaphoreII, 1, NULL);
    // wait for thread I
    WaitForSingleObject(hSemaphoreB, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    ReleaseSemaphore(hSemaphoreII, 1, NULL);
    // wait for thread I
    WaitForSingleObject(hSemaphoreB, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // release semaphore for thread I
    ReleaseSemaphore(hSemaphoreBFHI, 1, NULL);
    // wait for thread I
    WaitForSingleObject(hSemaphoreB, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // wait for thread D to finish
    WaitForSingleObject(hThread[3], INFINITE);
    // close thread D
    CloseHandle(hThread[3]);

    return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "e" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    ReleaseSemaphore(hSemaphoreBFHI, 1, NULL);
    WaitForSingleObject(hSemaphoreF, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "g" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    ReleaseSemaphore(hSemaphoreBFHI, 1, NULL);
    WaitForSingleObject(hSemaphoreHH, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    ReleaseSemaphore(hSemaphoreII, 1, NULL);
    WaitForSingleObject(hSemaphoreHH, INFINITE);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hSemaphoreH, INFINITE);
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(hMutex);
        computation();
        ReleaseSemaphore(hSemaphoreI, 1, NULL);
    }

    return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // wait for thread A to finish
    WaitForSingleObject(hThread[0], INFINITE);
    // close thread A
    CloseHandle(hThread[0]);

    // wait 1st step of B
    WaitForSingleObject(hSemaphoreII, INFINITE);
    ReleaseSemaphore(hSemaphoreB, 1, NULL);

    // start thread C
    hThread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
    if (hThread[2] == NULL) {
        std::cerr << "Can't create thread C. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // start thread D
    hThread[3] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
    if (hThread[3] == NULL) {
        std::cerr << "Can't create thread D. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // wait for thread C to finish
    WaitForSingleObject(hThread[2], INFINITE);
    // close thread C
    CloseHandle(hThread[2]);

    // wait for thread B
    WaitForSingleObject(hSemaphoreII, INFINITE);
    ReleaseSemaphore(hSemaphoreB, 1, NULL);

    // start thread E
    hThread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
    if (hThread[4] == NULL) {
        std::cerr << "Can't create thread E. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // start thread F
    hThread[5] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
    if (hThread[5] == NULL) {
        std::cerr << "Can't create thread F. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // start thread H
    hThread[7] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
    if (hThread[7] == NULL) {
        std::cerr << "Can't create thread H. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // wait for thread E to finish
    WaitForSingleObject(hThread[4], INFINITE);
    // close thread E
    CloseHandle(hThread[4]);

    // wait for B, F and H threads
    WaitForSingleObject(hSemaphoreBFHI, INFINITE);
    WaitForSingleObject(hSemaphoreBFHI, INFINITE);
    WaitForSingleObject(hSemaphoreBFHI, INFINITE);

    ReleaseSemaphore(hSemaphoreB, 1, NULL);
    ReleaseSemaphore(hSemaphoreF, 1, NULL);
    ReleaseSemaphore(hSemaphoreHH, 1, NULL);

    // start thread G
    hThread[6] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
    if (hThread[6] == NULL) {
        std::cerr << "Can't create thread G. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    // wait for thread B to finish
    WaitForSingleObject(hThread[1], INFINITE);
    // close thread B
    CloseHandle(hThread[1]);

    // wait for thread F to finish
    WaitForSingleObject(hThread[5], INFINITE);
    // close thread F
    CloseHandle(hThread[5]);

    // wait for thread G to finish
    WaitForSingleObject(hThread[6], INFINITE);
    // close thread G
    CloseHandle(hThread[6]);

    WaitForSingleObject(hSemaphoreII, INFINITE);
    ReleaseSemaphore(hSemaphoreHH, 1, NULL);

    // start thread K
    hThread[9] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
    if (hThread[9] == NULL) {
        std::cerr << "Can't create thread K. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hSemaphoreI, INFINITE);
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(hMutex);
        computation();
        ReleaseSemaphore(hSemaphoreK, 1, NULL);
    }

    // wait for thread H to finish
    WaitForSingleObject(hThread[7], INFINITE);
    // close thread H
    CloseHandle(hThread[7]);
    // wait for thread K to finish
    WaitForSingleObject(hThread[9], INFINITE);
    // close thread K
    CloseHandle(hThread[9]);

    // start thread M
    hThread[10] = CreateThread(NULL, 0, thread_m, NULL, 0, &ThreadID);
    if (hThread[10] == NULL) {
        std::cerr << "Can't create thread M. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // wait for thread M to finish
    WaitForSingleObject(hThread[10], INFINITE);
    // close thread M
    CloseHandle(hThread[10]);

    return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hSemaphoreK, INFINITE);
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(hMutex);
        computation();
        ReleaseSemaphore(hSemaphoreH, 1, NULL);
    }

    return 0;
}
DWORD WINAPI thread_m(LPVOID lpParam) {
    // lpParam is not used
    UNREFERENCED_PARAMETER(lpParam);

    // perform computations
    for (int i = 0; i < 3; ++i) {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "m" << std::flush;
        ReleaseMutex(hMutex);
        computation();
    }

    return 0;
}

int lab3_init() {
    // initialize mutex
    hMutex = CreateMutex(NULL, FALSE, NULL);
    if (hMutex == NULL) {
        std::cerr << "Mutex init failed" << std::endl;
        return 1;
    }

    // initialize threads border helper semaphore
    hSemaphoreB = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreB == NULL) {
        std::cerr << "Semaphore B init failed" << std::endl;
        return 1;
    }
    hSemaphoreII = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreII == NULL) {
        std::cerr << "Semaphore II init failed" << std::endl;
        return 1;
    }
    hSemaphoreF = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreF == NULL) {
        std::cerr << "Semaphore F init failed" << std::endl;
        return 1;
    }
    hSemaphoreHH = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreHH == NULL) {
        std::cerr << "Semaphore HH init failed" << std::endl;
        return 1;
    }
    hSemaphoreBFHI = CreateSemaphore(NULL, 0, 3, NULL);
    if (hSemaphoreBFHI == NULL) {
        std::cerr << "Semaphore BFHI init failed" << std::endl;
        return 1;
    }
    // initialize semaphore K
    hSemaphoreK = CreateSemaphore(NULL, 1, 1, NULL);
    if (hSemaphoreK == NULL) {
        std::cerr << "Semaphore K init failed" << std::endl;
        return 1;
    }
    // initialize semaphore H
    hSemaphoreH = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreH == NULL) {
        std::cerr << "Semaphore H init failed" << std::endl;
        return 1;
    }
    // initialize semaphore I
    hSemaphoreI = CreateSemaphore(NULL, 0, 1, NULL);
    if (hSemaphoreI == NULL) {
        std::cerr << "Semaphore I init failed" << std::endl;
        return 1;
    }

    // start the "A" thread
    hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
    if (hThread[0] == NULL) {
        std::cerr << "Can't create thread A. Error: " << GetLastError() << std::endl;
        return 1;
    }
    // start the "B" thread
    hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
    if (hThread[1] == NULL) {
        std::cerr << "Can't create thread B. Error: " << GetLastError() << std::endl;
        return 1;
    }
    // start the "I" thread
    hThread[8] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
    if (hThread[8] == NULL) {
        std::cerr << "Can't create thread I. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // ... and wait for thread "I" to finish
    WaitForSingleObject(hThread[8], INFINITE);

    // close thread "I"
    CloseHandle(hThread[8]);

    // close mutex
    CloseHandle(hMutex);
    // close semaphores
    CloseHandle(hSemaphoreB);
    CloseHandle(hSemaphoreII);
    CloseHandle(hSemaphoreF);
    CloseHandle(hSemaphoreHH);
    CloseHandle(hSemaphoreBFHI);
    CloseHandle(hSemaphoreK);
    CloseHandle(hSemaphoreH);
    CloseHandle(hSemaphoreI);
    // print a new line
    std::cout << std::endl;
    return 0;
}
