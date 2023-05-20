#include <stdio.h>

int main() {
    unsigned int octet1, octet2, octet3, octet4;
    printf("Enter IP address (in decimal format): ");
    scanf("%u.%u.%u.%u", &octet1, &octet2, &octet3, &octet4);

    unsigned int ipAddress = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
    unsigned int subnetMask;
    unsigned int subnetAddress;

    // Determine the class based on the IP address and set the subnet mask accordingly
    if ((octet1 >= 0 && octet1 <= 127)) {
        printf("Class A network\n");
        printf("Subnet mask: 255.0.0.0\n");
        subnetMask = 0xFF000000;
    } else if ((octet1 >= 128 && octet1 <= 191)) {
        printf("Class B network\n");
        printf("Subnet mask: 255.255.0.0\n");
        subnetMask = 0xFFFF0000;
    } else if ((octet1 >= 192 && octet1 <= 223)) {
        printf("Class C network\n");
        printf("Subnet mask: 255.255.255.0\n");
        subnetMask = 0xFFFFFF00;
    } else if ((octet1 >= 224 && octet1 <= 239)) {
        printf("Class D network (Multicast)\n");
        printf("No specific subnet mask for Class D networks\n");
        return 0;
    } else if ((octet1 >= 240 && octet1 <= 255)) {
        printf("Class E network (Reserved)\n");
        printf("No specific subnet mask for Class E networks\n");
        return 0;
    } else {
        printf("Invalid IP address\n");
        return 0;
    }

    subnetAddress = ipAddress & subnetMask;

    printf("Subnet Address: %u.%u.%u.%u\n", (subnetAddress >> 24) & 0xFF, (subnetAddress >> 16) & 0xFF,
           (subnetAddress >> 8) & 0xFF, subnetAddress & 0xFF);

    return 0;
}