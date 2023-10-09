DEXORY - CODING EXERCISE

1. REQUIREMENTS
    - CMake
    - cpp 20
    - OpenCV
    

2. BUILDING
    The code has been written and tested on a Mac.
    These are the step to compile on Mac/Linux:
    
        cmake -S . -B build
        cd build 
        make


3. EXECUTING
    Once the project has been compiled the executable will be generated in the build folder.
    You can run it with the following command:
    
            dexory <input_filename_path> <output_directory_path>
    
    `<input_filename_path>` is the path to a file with AssetIDs following the structure provided in the test.txt
    file in the resources folder.
    
    `<output_directory_path>` is the path to the directory where the PNG images corresponding to the AssetIDs read from the input file
    will be generated.
    
    Example using the txt file provided, and running it from the build directory:
    
            ./dexory ../resources/test.txt .

    The std output would be:

                ID        Checksum
                --------------------
                0011      33
                0201      50
                1222      87
                1927      16
                2674      9
                4434      76
                5657      96
                6872      70
                7288      0
                9443      54
                
                PNG images generated in directory: .
     
     And the resulting PNG images can be founf in the `results` folder.


4. RUNNING TESTS
    This project uses GoogleTest and GoogleMock for testing.
    After having built the project and inside the build folder run:

        ctest


5. DESIGN
    These are the classes implemented for my solution:
        - `Digit`: Represent a single digit of an AssetID. This is a numeric character between 0-9.
        - `AssetID`: This represent an ID as specified in the requirements with 4 digits.
        - `Exporter`: This is an interface used to be able to export an AssetID to different formats.
        - `TextExporter`: Implementation the Exporter interface to be able to export an AssetID as text
                          This was not requirement in the especification, but is provided as an example on 
                          how the interface can be used for different types of encodings when importing.
        - `PNGExporter`: Implementation the Exporter interface to be able to export an AssetID as a PNG image 
                         as described in the requirements.
        - `MockExporter`: Implementation the Exporter interface for testing purposes.
    
    The class `AssetID` is made of an array of `Digits`. This class has methods to calculate the checksum and to export
    the data to different format. The format used for exporting is provided as an arguement of type `Exporter`.
    Different implementation of the `Exporter` interface allows the class `AssetID` to export the data in different ways
    without having to modidy/recompile its code, followinf the "open/close" principle.

    In the main function, the file with the IDs is read, then the AssetID objects are created and the checksum calculated and displayed.
    Finally the PNG images are created.
    
    All classes are unit tested. The tests for TextPNGTest are more similar to an integration test than a unit test, since they rely on the PNG provided in the exercise files to check the result.

    The helping functions created in the main.cpp file don't have unit tests, and that was a conscious decision I would be happy to discuss. Adding those test wouldn't be complicated, but I think it wasn't necessary in this case.
    

6. RESPONSE TO QUESTION 4 
    After the initial implementation the customer realises that they need to support more than
    10,000 unique items using the same 6 digit displays. Describe any possible way(s) you could
    change the implementation detailed above to support this request.

    Right now the limiting factor is that we can only have 4 digits, representing numbers from 0000 to 9999.
    - Assuming the reserved bits of the PNG image can be used, one possible solution would be increment the number of digits per ID:
        If we wanted more IDs we could add another digit and we would be able to represent 10000 numbers 
        ranging from 00000  to 99999.
        We would need to modify the hashing function probably like this:
            c = (a1 + (10 * a2) + (100 * a3) + (1000 * a4) + (10000 * a5)) mod 97
        But the modulus number might required further investigation to avoid too many collisions.
        Then in the PNG representation we would need 7 bytes (5 ID +2 checksum), and we would used some of the reserved bits. which means that instead of using bits 7-55 we would use 7-63.
    
    - If we can't use the reserved bits in the PNG, we could use hexadecimal values in the 7 segment encoding to be able to represent 16 values per digit instead of just 10.
    This could be further extended to even more values using all letters of the alphabet or other symbols that could be represented with a 7 segment display.
    Here's an example where we use hexadecimal:
                0 --> 01110111
                1 --> 01000010
                2 --> 10110110
                3 --> 11010110
                4 --> 11000011
                5 --> 11010101
                6 --> 11110101
                7 --> 01000110
                8 --> 11110111
                9 --> 11010111
                A --> 11100111
                b --> 11110001 //B coincides with 8 if it's upper case, we could represented as lower case
                d --> 11110010 //D coincides with 0 if it's upper case, we could represented as lower case
                E --> 10110101
                F --> 10000101
