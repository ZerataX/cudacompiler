public class Example{

    public static void main(String[] args){
        Executor.init();

        final int numThreads = 8;
        final int numBlocks = 8;

        //Testdata
        float n = numThreads*numBlocks;
        float a = 5.1f;
        float[] x = new float[n];
        float[] y = new float[n];
        for (size_t i = 0; i < n; ++i) {
            x[i] = i;
            y[i] = 2*i;
        }

        //Initialize Arguments
        KernelArg aArg, xArg, yArg, outArg, nArg;
        aArg = KernelArg.create(a);
        xArg = KernelArg.create(x, false);
        yArg = KernelArg.create(y, false);
        outArg = KernelArg.create(n*4);
        nArg = KernelArg.create(n);

        //Create Program
        Program saxpy = Program.create(loadFile("kernels/saxpy"), "saxpy");

        //Create Kernel
        Kernel saxpyKernel = saxpy.compile();

        //Compile and launch Kernel
        saxpyKernel.launch(new KernelArg[]{aArg, xArg, yArg, outArg, nArg}, numThreads, numBlocks);

        //Get Result
        float[] out = outArg.asFloatArray();
    }

    private static String loadFile(String filename){
        return new String(Files.readAllBytes(new File(kernelName).toPath()));
    }
}