import fs from 'fs';
import path from 'path';
import crypto from 'crypto';
import Yaz0 from 'yaz0';

import { fileExists } from './util';

function fsRetry<T>(fn: () => Promise<T>, retries = 5): Promise<T> {
  return fn().catch((err) => {
    if (retries > 0) {
      return new Promise((reesolve, reject) => {
        setTimeout(() => {
          fsRetry(fn, retries - 1).then(reesolve, reject);
        }, 100);
      });
    }
    throw err;
  });
}

export const compressFile = async (data: Buffer): Promise<Buffer> => {
  let filename = "";

  if (!process.env.BROWSER) {
    const hash = crypto.createHash('sha256').update(data).digest('hex');
    const dir = path.resolve('build', 'cache', 'yaz0', hash.slice(0, 2));
    filename = path.resolve(dir, hash);

    /* Check for the file in cache */
    await fs.promises.mkdir(dir, { recursive: true });
    if (await fileExists(filename)) {
      return fsRetry(() => fs.promises.readFile(filename));
    }
  }

  /* Cache miss - compress */
  const compressed = await Yaz0.compress(data, 7);
  if (!process.env.BROWSER) {
    await fsRetry(() => fs.promises.writeFile(filename, compressed));
  }
  return compressed;
};
